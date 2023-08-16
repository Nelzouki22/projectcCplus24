#include <iostream>
#include <string>
#include <vector>
#include <map>

class File {
public:
    File(const std::string &name, int size)
        : name(name), size(size) {}

    const std::string &getName() const {
        return name;
    }

    int getSize() const {
        return size;
    }

private:
    std::string name;
    int size;
};

class Directory {
public:
    Directory(const std::string &name)
        : name(name) {}

    void addFile(const File &file) {
        files.push_back(file);
    }

    void listContents() const {
        std::cout << "Contents of directory " << name << ":\n";
        for (const File &file : files) {
            std::cout << "File: " << file.getName() << "\tSize: " << file.getSize() << " bytes\n";
        }
    }

private:
    std::string name;
    std::vector<File> files;
};

class FileSystem {
public:
    void createDirectory(const std::string &name) {
        directories[name] = Directory(name);
    }

    void createFile(const std::string &directoryName, const std::string &fileName, int size) {
        auto it = directories.find(directoryName);
        if (it != directories.end()) {
            it->second.addFile(File(fileName, size));
        } else {
            std::cout << "Directory not found.\n";
        }
    }

    void listDirectoryContents(const std::string &directoryName) const {
        auto it = directories.find(directoryName);
        if (it != directories.end()) {
            it->second.listContents();
        } else {
            std::cout << "Directory not found.\n";
        }
    }

private:
    std::map<std::string, Directory> directories;
};

int main() {
    FileSystem fileSystem;

    fileSystem.createDirectory("documents");
    fileSystem.createDirectory("images");

    fileSystem.createFile("documents", "report.txt", 1024);
    fileSystem.createFile("images", "photo.jpg", 2048);

    fileSystem.listDirectoryContents("documents");
    fileSystem.listDirectoryContents("images");

    return 0;
}
