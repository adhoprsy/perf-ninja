#include "solution.hpp"
#include <algorithm>
#ifdef SOLUTION

bool solution(MatrixOfDoubles &in, MatrixOfDoubles &out) {

  MatrixOfDoubles tmp(in);

  int size = in.size();
  const int block_size = 16;
  for (int i_ = 0; i_ < size; i_ += block_size)
    for (int j_ = 0; j_ < size; j_ += block_size)
      for (int i = i_; i < size && i < i_ + block_size; ++i)
        for (int j = j_; j < size && j < j_ + block_size; ++j)
          out[i][j] = in[j][i];

  // for (int i_ = 0; i_ < size / block_size; i_++)
  //   for (int j_ = 0; j_ < size / block_size; j_++)
  //     for (int i = 0; i < block_size; ++i)
  //       for (int j = 0; j < block_size; ++j)
  //         out[i_ * block_size + i][j_ * block_size + j] =
  //             tmp[j_ * block_size + i][i_ * block_size + j];

  return out[0][size - 1];
}

#else
bool solution(MatrixOfDoubles &in, MatrixOfDoubles &out) {
  int size = in.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      out[i][j] = in[j][i];
    }
  }
  return out[0][size - 1];
}

#endif

/*
1 2 3 4
5 6 7 8
4 3 2 1
8 7 6 5

1 5 3 7
2 6 4 8
4 8 2 6
3 7 1 5

1 5 4 8
2 6 3 7
3 7 2 6
4 8 1 5
*/
