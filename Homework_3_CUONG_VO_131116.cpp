#include <iostream>
#include <string>

using namespace std;

// Group 1
// 1. Count the Smiley Faces :)
// Create a function that takes an array of strings and return the number of smiley faces contained 
// within it. These are the components that make up a valid smiley:
// - a smiley has eyes. Eyes can be : or ;
// - a smiley has a nose but it doesn't have to. A nose can be - or ~ or nothing
// - a smiley has a mouth which can be ) or D
// No other characters are allowed except for those mentioned above.

// Group 2
// 1. Multicalculator
// Write a function that takes two integer values and returns the result set of basic arithmetic 
// operations (such as addition or modulo). Note that if the numbers given are not integers the function
// returns an empty array. You can use more operators if you want (for overloading).

// 5. Diamond Shaped Array
// Create a function that returns an array that expands by 1 from 1 to the value of the input, and then 
// reduces back to 1. Items in the lists will be the same as the length of the lists. Check if the given 
// value is an integer greater than 0, otherwise return an empty 2d array.

void smile_create(string (&smile)[12]) {
    string eyes[2] = {":", ";"};
    string nose[3] = {"-", "~", ""};
    string mouth[2] = {")", "D"};

    int index = 0;

    for (int i=0; i<2 ; i++){
        for (int j=0; j<3 ; j++){
            for (int z=0; z<2 ; z++){
                smile[index] = eyes[i] + nose[j] + mouth[z];
                index += 1;
            }
        }
    }

}

bool smile_check (string x, string (&smile)[12]){
    for (int j=0; j<12; j++){
        if (x == smile[j]) return true;
    }
    return false;
    
}

int** diamond(int value){
    int size = 2 * value - 1;
    int** result = new int*[size];
    int row = 0;
    for (int i=1; i <= value ; ++i){
        result[row] = new int[i];
        for (int j=0; j<i; ++j){
            result[row][j] = i;
        }
        ++row;
    }
    
    for (int i=value-1; i>=1; --i){
        result[row] = new int[i];
        for (int j=0; j<i; ++j){
            result[row][j] = i;
        }
        ++row;
    }

    return result;
}

void multical(int a, int b, int (&res)[3]) {
    res[0] = a + b;
    res[1] = a - b;
    res[2] = a * b;
}

void multical(float a, float b, float (&res_1), string opt) {
    res_1 = a/b;
}

void multical(int a, int b, int (&res_2), string opt) {
    res_2 = a%b;
}


int main() 
{
    cout << "==========================================" << endl;
    string smile[12];
    smile_create(smile);
    int n;
    cout << "Input number of Smile: ";
    cin >> n;
    int total_smile;
    total_smile = 0;
    string s;
    for (int i=0; i<n; i++){
        cout << "Smile number " << i+1 << ": ";
        cin >> s;
        if (smile_check(s, smile)) total_smile +=1;
        }
    cout << "Total smile: " << total_smile << endl;
    cout << "==========================================" << endl;
    double a;
    double b;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    int res[3];
    float res_1;
    int res_2;
    string cal_string;
    if (((int) a != a) or ((int) b != b) or (b == 0)) cout << "[]" << endl;
    else 
    {
        multical((int) a, (int) b, res);
        multical(a, b, res_1, "/");
        multical((int) a, (int) b, res_2, "%");
        cal_string = "[" + cal_string + to_string(res[0]) + ", ";
        cal_string = cal_string + to_string(res[1]) + ", ";
        cal_string = cal_string + to_string(res[2]) + ", ";
        cal_string = cal_string + to_string(res_1) + ", ";
        cal_string = cal_string + to_string(res_2) + "]";
        cout << cal_string << endl;
    }
    cout << "==========================================" << endl;    
    double diamond_h;
    cout << "Input height of diamonds: ";
    cin >> diamond_h;
    string diamond_s, tmp,num;
    if (((int) diamond_h == diamond_h) and (diamond_h > 0)) {
        int** result = diamond(diamond_h);
        for (int i=0; i<2*diamond_h-1; i++){
            for (int j=0; j<=result[i][0]-1; j++){
                if (j != result[i][0]-1) tmp = tmp + to_string(result[i][j]) + ", ";
                else tmp = tmp + to_string(result[i][j]);
            }
        if (i != 2 * diamond_h - 2) diamond_s = diamond_s + "[" + tmp + "], ";
        else diamond_s = diamond_s + "[" + tmp + "]";
        tmp = "";
        }
        cout << "[" + diamond_s + "]";
    } else cout << "[[]]";
}