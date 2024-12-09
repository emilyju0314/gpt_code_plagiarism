#include <iostream>
#include <string>

void playMusic(std::string input) {
    std::string result = "";
    std::string currentNote = "";
    int currentOctave = 4;
    int currentDefaultDuration = 4;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'O') {
            int octave = input[i + 1] - '0';
            if (input[i + 2] == '>') {
                if (currentOctave < 8) {
                    currentOctave++;
                }
            } else if (input[i + 2] == '<') {
                if (currentOctave > 1) {
                    currentOctave--;
                }
            } else {
                currentOctave = octave;
            }
            i += 2;
        } else if (input[i] == 'L') {
            currentDefaultDuration = input[i + 1] - '0';
            i++;
        } else if (input[i] == 'R') {
            char duration = input[i + 1];
            result += 'R';
            result += duration;
            if (duration == currentDefaultDuration + '0') {
                i++;
            } else if (duration == '.') {
                i += 2;
            } else {
                i++;
            }
        } else if (input[i] == 'V') {
            int volume = std::stoi(input.substr(i + 1, 3));
            result += 'V';
            result += std::to_string(volume);
            i += 2;
        } else {
            currentNote += input[i];
            if (input[i] == 'C' || input[i] == 'D' || input[i] == 'E' || input[i] == 'F' || input[i] == 'G' || input[i] == 'A' || input[i] == 'B') {
                char duration = input[i + 1];
                result += currentNote;
                if (duration == currentDefaultDuration + '0') {
                    i++;
                } else if (duration == '.') {
                    i += 2;
                } else {
                    i++;
                }
                currentNote = "";
            }
        }
    }
    std::cout << result << std::endl;
}

int main() {
    std::string input;
    int caseNum = 1;
    
    while (true) {
        std::getline(std::cin, input);
        if (input == "*") {
            break;
        }
        std::cout << "Case " << caseNum << ": ";
        playMusic(input);
        caseNum++;
    }
    
    return 0;
}