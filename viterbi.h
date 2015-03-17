#ifndef _BPJ_VITERBI_H
#define _BPJ_VITERBI_H

#include <byteimage/matrix.h>
#include <vector>

//TODO: Use logarithmic math

class HMM {
public:
  typedef unsigned int State;
  typedef unsigned int Output;

  Matrix initial_table;//pi_k
  Matrix transition_table;//a_{i,j}
  Matrix observation_table;//p_{k,y} = P(y|k)

  HMM();
  HMM(int nstates, int noutputs);

  int states() const;
  int outputs() const;

  void setInitialProbability(State state, double p);
  void setTransitionProbability(State from, State to, double p);
  void setOutputProbability(State state, Output output, double p);
};

class Viterbi {
protected:
  Matrix V;//V_{t,k}
  std::vector<HMM::State> backptrs;//backptr_{t,k} stored row-major

public:
  Viterbi(const HMM& model, std::vector<HMM::Output> observations);

  HMM::State getState(int t) const;
  double getProbability(HMM::State state, int t) const;
  std::vector<HMM::State> getPath() const;

  inline const Matrix& getMatrix() const {return V;}
};

#endif
