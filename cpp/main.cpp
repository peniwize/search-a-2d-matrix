/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/search-a-2d-matrix/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>
#include <cassert>
#include <chrono>
#include <doctest/doctest.h> //!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md
#include <iterator>
#include <queue>
#include <vector>
#include <set>
#include <span>

using namespace std;

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

class Solution {
public:
    /*!
        You are given an m x n integer matrix matrix with the following two properties:

        Each row is sorted in non-decreasing order.
        The first integer of each row is greater than the last integer of the previous row.
        Given an integer target, return true if target is in matrix or false otherwise.

        You must write a solution in O(log(m * n)) time complexity.
        
        Time = O(n*log(m))
    */
#if 0
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto const& nums : matrix) {
            auto left = nums.begin();
            auto right = nums.end();
            while (left < right) {
                auto mid = left + (right - left) / 2;
                if (*mid < target) {
                    left = mid + 1;
                } else if (*mid == target){
                    return true;
                } else {
                    right = mid;
                }
            }
        }
        return false;
    }
#endif // #if 0

    /*!
        You are given an m x n integer matrix matrix with the following two properties:

        Each row is sorted in non-decreasing order.
        The first integer of each row is greater than the last integer of the previous row.
        Given an integer target, return true if target is in matrix or false otherwise.

        You must write a solution in O(log(m * n)) time complexity.
        
        Time = O(log(m*n))
    */
#if 0
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.empty()) {
            auto const height = matrix.size();
            auto const width = matrix[0].size();

            ssize_t left = 0; // begin
            ssize_t right = width * height; // end
            while (left < right) {
                auto const mid = left + (right - left) / 2; // Virtual midpoint.
                auto const y = mid / width;
                auto const x = mid % width;
                if (matrix[y].empty()) {
                    return false;
                }
                auto const& element = matrix[y][x];
                if (element < target) {
                    left = mid + 1;
                } else if (element == target){
                    return true;
                } else {
                    right = mid;
                }
            }
        }

        return false;
    }
#endif // #if 0

    /*!
        You are given an m x n integer matrix matrix with the following two properties:

        Each row is sorted in non-decreasing order.
        The first integer of each row is greater than the last integer of the previous row.
        Given an integer target, return true if target is in matrix or false otherwise.

        You must write a solution in O(log(m * n)) time complexity.
        
        Time = O(m+log2(n)) => O(m) or O(log2(n)) [for very wide short matrices]
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto const& row : matrix) {
            if (row.front() <= target && row.back() >= target) {
                auto left = row.begin();
                auto right = row.end();
                while (left < right) {
                    auto mid = left + (right - left) / 2;
                    if (*mid < target) {
                        left = mid + 1;
                    } else if (*mid == target){
                        return true;
                    } else {
                        right = mid;
                    }
                }

                break;
            }
        }

        return false;
    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

struct elapsed_time_t
{
    std::chrono::steady_clock::time_point start{};
    std::chrono::steady_clock::time_point end{};
    
    elapsed_time_t(
        std::chrono::steady_clock::time_point start
        , std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now()
    ) : start{std::move(start)}, end{std::move(end)} {}
};

std::ostream&
operator<<(std::ostream& os, elapsed_time_t const& et)
{
    auto const elapsed_time = et.end - et.start;
    os << std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count()
       << '.' << (std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count() % 1000)
       << " ms";
    return os;
}

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    vector<vector<int>> value{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    auto const expected = true;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        CHECK(expected == Solution{}.searchMatrix(value, 3));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

/*
    End of "main.cpp"
*/
