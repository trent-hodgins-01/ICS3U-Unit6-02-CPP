// Copyright (c) 2021 Trent Hodgins All rights reserved

// Created by Trent Hodgins
// Created on 10/22/2021
// This is the list_array program
// The program generates and displays 10 random numbers between 1-100
// The program then figures out and displays the largest of the 10 numbers

#include <iostream>
#include <random>
#include <ctime>
#include <array>


template<size_t N>
int LargestOfNumbers(std::array<int, N> listofNumbers) {
    int largestNumber;

    largestNumber = listofNumbers[0];
    for (int userX = 1; userX < N; userX++) {
        if (listofNumbers[userX] > largestNumber) {
            largestNumber = listofNumbers[userX];
        }
    }

    return largestNumber;
}


main() {
    // this function uses an array to generate 10 random numbers
    //  from 1-100 and output the mean

    std::array<int, 10> randomNum;
    int listArray;
    int biggestNumber;
    int sumOf = 0;
    int number = 0;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 100);
    // [0, 100]


    // output
    for (int loop_count = 0; loop_count < 10; loop_count++) {
        listArray = idist(rgen);
        randomNum[loop_count] = listArray;
    }

    std::cout << "The random numbers are:" << std::endl;
    std::cout << "" << std::endl;

    for (int loopCounter; loopCounter < 10; loopCounter++) {
        number = loopCounter + 1;
        std::cout << "Random number " << number << " is " <<
                      randomNum[loopCounter] << std::endl;
        sumOf += randomNum[loopCounter];
    }

    biggestNumber = LargestOfNumbers(randomNum);

    std::cout << "\nThe largest number is "
    << biggestNumber << std::endl;
    std::cout << "\nDone." << std::endl;
}
