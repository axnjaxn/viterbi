#include "viterbi.h"

HMM::HMM() { }

HMM::HMM(int nstates, int noutputs) :
  initial_table(nstates, 1),
  observation_table(nstates, noutputs),
  transition_table(nstates, nstates) { }

int HMM::states() const {
  return observation_table.rows();
}

int HMM::outputs() const {
  return observation_table.cols();
}

void HMM::setInitialProbability(State state, double p) {
  initial_table.at(state) = p;
}

void HMM::setTransitionProbability(State from, State to, double p) {
  transition_table.at(from, to) = p;
}

void HMM::setOutputProbability(State state, Output output, double p) {
  observation_table.at(state, output) = p;
}

Viterbi::Viterbi(const HMM& model, std::vector<HMM::Output> observations) : 
  V(observations.size(), model.states()), 
  backptrs(observations.size() * model.states()) {
  for (int k = 0; k < V.cols(); k++)
    V.at(0, k) = model.initial_table.at(k) * model.observation_table.at(k, observations[0]);

  double p;
  for (int t = 1; t < V.rows(); t++) {
    for (int k = 0; k < V.cols(); k++)
      for (int i = 0; i < V.cols(); i++) {
	p = model.observation_table.at(k, observations[t]) * model.transition_table.at(i, k) * V.at(t - 1, i);
	if (p > V.at(t, k)) {
	  V.at(t, k) = p;
	  backptrs[t * model.states() + k] = i;
	}
      }
  }
}

HMM::State Viterbi::getState(int t) const {
  HMM::State max_index = 0;

  for (HMM::State i = 1; i < V.cols(); i++)
    if (V.at(t, i) > V.at(t, max_index))
      max_index = i;

  return max_index;
}

double Viterbi::getProbability(HMM::State state, int t) const {
  return V.at(t, state);
}

std::vector<HMM::State> Viterbi::getPath() const {
  std::vector<HMM::State> path(V.rows());

  path[path.size() - 1] = getState(path.size() - 1);
  for (int t = path.size() - 1; t > 0; t--)
    path[t - 1] = backptrs[t * V.cols() + path[t]];

  return path;
}
