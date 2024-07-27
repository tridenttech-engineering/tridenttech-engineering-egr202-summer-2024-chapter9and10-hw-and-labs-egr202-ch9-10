#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <unistd.h> // For STDIN_FILENO, STDOUT_FILENO, dup, dup2, and close
using namespace std;

void runTest() {
    // Test case 1
    string input1 = "16000\n3000\n0.08\n0.03\n4\n";
    string expected_output1_1 = "317.37";
    string expected_output1_2 = "15233.76";
    string expected_output1_3 = "354.15";
    string expected_output1_4 = "16999.20";

    // Helper function to run a single test case
    auto runSingleTest = [](const string& input, const string& expected_output1, const string& expected_output2, const string& expected_output3, const string& expected_output4) {
        // Create temporary files for input and output redirection
        FILE *input_file = tmpfile();
        FILE *output_file = tmpfile();

        // Write the input to the input file
        fputs(input.c_str(), input_file);
        rewind(input_file);

        // Redirect stdin to the input file
        int input_fd = fileno(input_file);
        int saved_stdin_fd = dup(STDIN_FILENO);
        dup2(input_fd, STDIN_FILENO);

        // Redirect stdout to the output file
        int output_fd = fileno(output_file);
        int saved_stdout_fd = dup(STDOUT_FILENO);
        dup2(output_fd, STDOUT_FILENO);

        // Call the original program's main function
        int result = system("./hw9-19");

        // Restore stdin and stdout
        dup2(saved_stdin_fd, STDIN_FILENO);
        dup2(saved_stdout_fd, STDOUT_FILENO);
        close(saved_stdin_fd);
        close(saved_stdout_fd);

        // Check if the system call was successful
        if (result != 0) {
            cout << "Test Failed: Program did not run successfully" << endl;
            exit(-1);
        }

        // Read the output from the output file
        rewind(output_file);
        char buffer[256];
        string actual_output;
        while (fgets(buffer, sizeof(buffer), output_file)) {
            actual_output += buffer;
        }

        // Close and remove the temporary files
        fclose(input_file);
        fclose(output_file);

        // Debugging information
        cout << "Expected Output 1:\n" << expected_output1 << endl;
        cout << "Expected Output 2:\n" << expected_output2 << endl;
        cout << "Expected Output 3:\n" << expected_output3 << endl;
        cout << "Expected Output 4:\n" << expected_output4 << endl;
        cout << "Actual Output:\n" << actual_output << endl;

        // Compare the actual output to the expected values
        if (actual_output.find(expected_output1) == string::npos || 
            actual_output.find(expected_output2) == string::npos || 
            actual_output.find(expected_output3) == string::npos || 
            actual_output.find(expected_output4) == string::npos) {
            cout << "Test Failed: Output does not contain expected values" << endl;
            exit(-1);
        }

        cout << "Test passed!" << endl;
    };

    // Run the individual test cases
    runSingleTest(input1, expected_output1_1, expected_output1_2, expected_output1_3, expected_output1_4);
}

int main() {
    try {
        runTest();
    } catch (const exception &e) {
        cout << "Test Failed: " << e.what() << endl;
        return -1;
    } catch (...) {
        cout << "Test Failed: Unknown error occurred" << endl;
        return -1;
    }
    return 0;
}
