/**
 *  Signals and Systems Project
 *
 *  Author : Dekas Dimitrios
 *  AEM : 3063
 *  Version : 3.1
 *  Date: Nov 12 10:01PM
 *  Language : C++
 */

/**
 *  Includes
 */
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

/**
 *  Constants
 */
#define A_LOWER_BOUND 11
#define SAMPLE_AUDIO_FILE "resources/sample_audio"
#define PINK_NOISE_FILE "resources/pink_noise"

/**
 *  Checks whether a string contains an integer or not.
 *
 *  @param str : the string that is going to be checked.
 *  @return a boolean value equal to true if the string contains an integer, false otherwise.
 */
bool isInteger(const std::string &str) {
    std::string::const_iterator it = str.begin();    // Create an iterator that points to the string beginning.
    while(it!=str.end() && std::isdigit(*it)) {   // Iterate over the string.
        it++;
    }
    return it==str.end() && !str.empty();    // Return true if the iterator points to the end of the non empty string.
}

/**
 *  Get the user's input and makes sure its an int inside the desired limits.
 *
 *  @return an int equal to input given by the user.
 */
int getIntInput() {
    int n;
    std::string input;
    std::getline(std::cin, input);
    while (true) {    // While will break as soon as a valid input is given by the user.
        if (isInteger(input)) {
            n = stoi(input);
            if (n >= A_LOWER_BOUND) {
                return n;
            }
        }
        std::cout << "The size of vector A should be an integer greater than " << A_LOWER_BOUND << std::endl;
        std::getline(std::cin, input);
    }
}

/**
 *  Fills a vector with n random numbers.
 *
 *  @param a : a vector we want to fill with random numbers.
 *  @param n : an integer indicating the amount of random numbers we want to fill the vector with.
 */
void fillA(std::vector<float> &a, int n) {
    std::random_device rd;
    std::mt19937 rand_engine(rd());
    std::uniform_real_distribution<float> distribution(0, 1);
    for (int i = 0; i < n; ++i) {
        a.push_back(distribution(rand_engine));
    }
}

/**
 *  Calculates the convolution of two signal.
 *
 *  @param x : a vector representing the x signal on certain values.
 *  @param h : a vector representing the h signal on certain values.
 *  @return a vector containing the result of the convolution of the two inputs.
 */
std::vector<float> myConvolve(const std::vector<float> &x, const std::vector<float> &h) {
    std::vector<float> c(x.size() + h.size() - 1, 0.0);
    for (unsigned long n = 0; n < x.size(); ++n) {
        for (unsigned long k = 0; k < h.size(); ++k) {
            c.at(n + k) += x.at(n)*h.at(k);
        }
    }
    return c;
}

/**
 *  The main function of the program.
 */
int main() {
    // Convolution
    std::cout << "Enter the wished size of vector A: " << std::endl;
    int size = getIntInput();
    std::vector<float> a;
    fillA(a, size);
    std::vector<float> b = {0.2, 0.2, 0.2, 0.2, 0.2};
    std::vector<float> convolution = myConvolve(a, b);
    for(auto &item : convolution) {
        std::cout << std::fixed << std::setprecision(6) << item << ' ';
    }
    // Wav Management

}