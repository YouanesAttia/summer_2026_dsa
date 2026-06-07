#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class FileHandler
{
private:
    std::ofstream file;
    std::string filename;

public:
    FileHandler(const std::string &name) : filename(name)
    {
        file.open(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file.");
        }
        std::cout << "[CONSTRUCTOR]: File '" << filename << "' opened and resource acquired.\n";
    }

    ~FileHandler()
    {
        if (file.is_open())
        {
            file.close();
            std::cout << "[DESTRUCTOR]: File '" << filename << "' closed and resource released.\n";
        }
    }

    void writeData(const std::string &data)
    {
        std::cout << "[WRITING]: Writing data to file...\n";
        file << data << std::endl;
    }
};

void runTest()
{
    std::cout << "--- Starting Test ---\n";
    try
    {
        FileHandler myFile("example.txt");

        myFile.writeData("This is a test of RAII.");

        std::cout << "[ERROR]: Simulating a critical failure/exception...\n";
        throw std::runtime_error("Unforeseen system error!");

        std::cout << "This line will never be printed.\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "[CATCH]: Caught exception: " << e.what() << "\n";
    }
    std::cout << "--- Test Finished ---\n";
}

int main()
{
    runTest();
    return 0;
}