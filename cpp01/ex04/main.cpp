#include <iostream>
#include <string>
#include <fstream>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create replace file." << std::endl;
        inputFile.close();
        return;
    }

    std::string content;
    std::string line;
    while (std::getline(inputFile, line)) {
        content += line;
        if (!inputFile.eof()) content += "\n";
    }

    std::string result;
    size_t pos = 0;
    size_t lastPos = 0;

    while ((pos = content.find(s1, lastPos)) != std::string::npos) {
        result.append(content, lastPos, pos - lastPos);
        result += s2;
        lastPos = pos + s1.length();
    }
    result.append(content, lastPos, std::string::npos);

    outputFile << result;
    inputFile.close();
    outputFile.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: The string to find (s1) cannot be empty." << std::endl;
        return 1;
    }

    replaceInFile(filename, s1, s2);

    return 0;
}