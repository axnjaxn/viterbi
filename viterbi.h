#ifndef _BPJ_VITERBI_H
#define _BPJ_VITERBI_H

#include <byteimage/matrix.h>
#include <vector>

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

  /*
   * This class uses logarithmic math,
   * so the following member functions provide 
   * a convenient way to get things in and out
   * without requiring a user of this class
   * to perform the math themselves.
   */

  void setInitialTable(const Matrix& pi);
  void setTransitionTable(const Matrix& a);
  void setObservationTable(const Matrix& p);

  void setInitialProbability(State state, double p);
  void setTransitionProbability(State from, State to, double p);
  void setOutputProbability(State state, Output output, double p);

  double getInitalProbability(State state) const;
  double getTransitionProbability(State from, State to) const;
  double getOutputProbability(State state, Output output) const;
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

  inline const Matrix& getMatrix() const {return V;}//Also logarithmic!
};

#endif
