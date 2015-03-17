#include "viterbi.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  vector<string> state_names {"Healthy", "Fever"};
  vector<string> observation_names {"Normal", "Cold", "Dizzy"};

  double pi[] {0.6, 0.4};
  double a[] {0.7, 0.3, 0.4, 0.6};
  double p[] {0.5, 0.4, 0.1, 0.1, 0.3, 0.6};

  HMM model(state_names.size(), observation_names.size());
  model.setInitialTable(Matrix(pi, 2, 1));
  model.setTransitionTable(Matrix(a, 2, 2));
  model.setObservationTable(Matrix(p, 2, 3));
  
  vector<HMM::Output> observations {0, 1, 2};
  cout << "Observations: ";
  for (auto obs : observations)
    cout << observation_names[obs] << " ";
  cout << endl;

  Viterbi v(model, observations);
  vector<HMM::State> path = v.getPath();
  cout << "Viterbi path: ";
  for (auto state : path)
    cout << state_names[state] << " ";
  cout << endl;

  cout << "This path has a probability of ";
  cout << v.getProbability(path[path.size() - 1], path.size() - 1) << endl;

  cout << "Full results:" << endl;
  for (int t = 0; t < observations.size(); t++) {
    for (int k = 0; k < state_names.size(); k++)
      cout << v.getProbability(k, t) << "\t";
    cout << endl;
  }

  return 0;
}
