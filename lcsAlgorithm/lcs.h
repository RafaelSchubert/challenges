#ifndef LCS_H__
#define LCS_H__


#include <algorithm>
#include <vector>


template<class TLeft, class TRight>
std::size_t lcs(TLeft const& left, TRight const& right)
{
    auto const rowLength = size(left) + 1;

    std::vector<std::size_t> scores(rowLength * (size(right) + 1), 0);
    std::size_t              scoreIndex = rowLength;

    for (auto const& leftValue : left)
    {
        ++scoreIndex;

        for (auto const& rightValue : right)
        {
            if (leftValue == rightValue)
                scores[scoreIndex] = scores[scoreIndex - rowLength - 1] + 1;
            else
                scores[scoreIndex] = std::max(scores[scoreIndex - 1], scores[scoreIndex - rowLength]);

            ++scoreIndex;
        }
    }

    return scores.back();
}


#endif
