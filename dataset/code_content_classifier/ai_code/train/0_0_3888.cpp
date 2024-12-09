#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Segment {
    int row;
    int left;
    int right;
    vector<char> chars;

    Segment(int r, int l, int r) : row(r), left(l), right(r) {}
};

vector<Segment> segments;
int current_segment_index = 0;
int cursor_pos = 0;

bool move_cursor_forward() {
    if (cursor_pos < segments[current_segment_index].right) {
        cursor_pos++;
        return true;
    } else {
        return false;
    }
}

bool move_cursor_backward() {
    if (cursor_pos > segments[current_segment_index].left) {
        cursor_pos--;
        return true;
    } else {
        return false;
    }
}

bool move_cursor_up() {
    int curr_row = segments[current_segment_index].row;
    for (int i = current_segment_index - 1; i >= 0; i--) {
        if (segments[i].row == curr_row - 1 && cursor_pos >= segments[i].left && cursor_pos <= segments[i].right) {
            segments[current_segment_index].row--;
            return true;
        }
    }
    return false;
}

bool move_cursor_down() {
    int curr_row = segments[current_segment_index].row;
    for (int i = current_segment_index + 1; i < segments.size(); i++) {
        if (segments[i].row == curr_row + 1 && cursor_pos >= segments[i].left && cursor_pos <= segments[i].right) {
            segments[current_segment_index].row++;
            return true;
        }
    }
    return false;
}

bool delete_char() {
    if (cursor_pos == segments[current_segment_index].right) {
        if (segments[current_segment_index].chars.size() == 1) {
            segments.erase(segments.begin() + current_segment_index);
            move_cursor_down();
        } else {
            segments[current_segment_index].chars.pop_back();
        }
        return true;
    } else {
        return false;
    }
}

bool create_segment() {
    if (cursor_pos < segments[current_segment_index].left || cursor_pos > segments[current_segment_index].right) {
        return false;
    }
    for (int i = 0; i < segments.size(); i++) {
        if (segments[i].row == segments[current_segment_index].row && cursor_pos >= segments[i].left && cursor_pos <= segments[i].right) {
            return false;
        }
    }
    char new_char = segments[current_segment_index].chars[cursor_pos - segments[current_segment_index].left];
    Segment new_seg(segments[current_segment_index].row - 1, cursor_pos, cursor_pos);
    new_seg.chars.push_back(new_char);
    segments.insert(segments.begin() + current_segment_index, new_seg);
    cursor_pos++;
    return true;
}

void insert_char(char c) {
    segments[current_segment_index].chars.insert(segments[current_segment_index].chars.begin() + cursor_pos - segments[current_segment_index].left, c);
    cursor_pos++;
}

int main() {
    int num_sessions;
    cin >> num_sessions;
    cin.ignore();

    for (int i = 0; i < num_sessions; i++) {
        string command;
        getline(cin, command);

        segments.clear();
        segments.push_back(Segment(1, 0, 0));
        current_segment_index = 0;
        cursor_pos = 0;

        segments[0].chars.push_back(command[0]);

        for (int j = 1; j < command.length(); j++) {
            char cmd = command[j];
            bool error = false;

            switch (cmd) {
                case 'F':
                    if (!move_cursor_forward()) error = true;
                    break;
                case 'B':
                    if (!move_cursor_backward()) error = true;
                    break;
                case 'P':
                    if (!move_cursor_up()) error = true;
                    break;
                case 'N':
                    if (!move_cursor_down()) error = true;
                    break;
                case 'D':
                    if (!delete_char()) error = true;
                    break;
                case 'C':
                    if (!create_segment()) error = true;
                    break;
                default:
                    insert_char(cmd);
            }

            if (error) {
                cout << "ERROR" << endl;
                break;
            }
        }

        if (!error) {
            for (char c : segments[0].chars) {
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}