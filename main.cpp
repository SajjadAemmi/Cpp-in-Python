#include <iostream>
#include <math.h>
#include "nlohmann/json.hpp"
#include "sajjad.cpp"

using namespace std;
using json = nlohmann::json;


void test_json()
{
    json j = {
        {"pi", M_PI},
        {"happy", true},
        {"name", "Sajjad"},
        {"answer", {
            {"everything", 42}
        }},
        {"list", {1, 0, 2}},
        {"object", {
            {"currency", "USD"},
            {"value", 42.99}
        }}
    };

    cout << j.dump(4) << endl;
}

int main()
{
    cout << "Welcome to this example" << endl;

    int x = 2;
    float y = 3.14;
    float z = add(x, y);
    cout << z << endl;

    int num = 2;
    cout << number2Word(num) << endl;

    char word[] = "one";
    cout << word2Number(word) << endl;

    char input_image_path[] = "io/input/image.jpg";
    char output_image_path[] = "io/output/result.jpg";
    testOpenCV(input_image_path, output_image_path);

    test_json();

    Sajjad obj;
    obj.testMethod();

    return 0;
}
