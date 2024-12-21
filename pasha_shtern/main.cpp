#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const std::string path_actual = "/brightness/sper";

const std::string path_max = "/brightness/sper";

std::string read_file(std::string current_path) {

    std::string line;
    std::ifstream in(current_path);

    if (in.is_open()) {
        std::getline(in, line);
    }

    in.close();

    return line;
}

void write_file(int brightness_value) {

    std::ofstream out;
    out.open(path_actual);

    if (out.is_open()) {

        out << brightness_value;
    }

    out.close();
}

int main(int argc, char *argv[]) {
    int step = 10;
    int brightness_value = 255;
    int brightness_min_value = 100;
    int brightness_max_value = read_file(path_max);

    for (int i = 0; i < argc; i++) {
        if (static_cast<std::string>(argv[i]) == "-up") {
            brightness_value = brightness_value + step > brightness_max_value ? brightness_max_value : brightness_value + step;
        } else if (static_cast<std::string>(argv[i]) == "-low") {
            brightness_value = brightness_value - step < brightness_min_value ? brightness_min_value : brightness_value - step;
        }
    }
    std::cout << read_file(path_actual) << '\n';
    write_file(brightness_value);
    std::cout << read_file(path_actual) << '\n';
}
