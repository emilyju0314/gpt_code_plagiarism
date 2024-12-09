int main() {
    int a, b, c, x, y, z;
    double result;

    cin >> a >> b >> c;
    cin >> x >> y >> z;

    if (a == 1 && b == 1 && c == 1) {
        result = static_cast<double>(x + y + z) / 3;
    } else {
        // Calculate the result based on the input values
    }

    cout << fixed << setprecision(1) << result << endl;

    return 0;
}