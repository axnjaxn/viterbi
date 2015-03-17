#ifndef _BPJ_VITERBI_GRID_H
#define _BPJ_VITERBI_GRID_H

#include <vector>

template <typename tn>
class Grid : private std::vector<tn> {
private:
  int nr, nc;

public:
  inline Grid() : nr(0), nc(0) { }
  inline Grid(int nr, int nc) : nr(nr), nc(nc) {this->resize(nr * nc);}
  inline Grid(const tn* mat, int nr, int nc) : Grid(nr, nc) {
    for (int i = 0; i < this->size(); i++)
      (*this)[i] = mat[i];
  }
  
  inline int rows() const {return nr;}
  inline int cols() const {return nc;}

  inline tn& at(int r, int c = 0) {return (*this)[r * nc + c];}
  inline tn at(int r, int c = 0) const {return (*this)[r * nc + c];}
};

#endif
