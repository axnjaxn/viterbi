viterbi
=======

A simple implementation of the Viterbi algorithm in C++11.

Usage
-----

You can build and run the included test program with `make run`, which
demonstrates the method using an example drawn from Wikipedia's article on the
Viterbi algorithm.


Test program
------------

The test case is a scenario where patients under a doctor's care exhibit
symptoms of a fever. From the wikipedia article:

> Consider a primitive clinic in a village. People in the village have a very
> nice property that they are either healthy or have a fever. They can only
> tell if they have a fever by asking a doctor in the clinic. The wise doctor
> makes a diagnosis of fever by asking patients how they feel. Villagers only
> answer that they feel normal, dizzy, or cold.

> Suppose a patient comes to the clinic each day and tells the doctor how she
> feels. The doctor believes that the health condition of this patient operates
> as a discrete Markov chain. There are two states, "Healthy" and "Fever", but
> the doctor cannot observe them directly, that is, they are hidden from him.
> On each day, there is a certain chance that the patient will tell the doctor
> she has one of the following feelings, depending on her health condition:
> "normal", "cold", or "dizzy". Those are the observations. The entire system
> is that of a hidden Markov model (HMM).

> The patient visits three days in a row and the doctor discovers that on the
> first day she feels normal, on the second day she feels cold, on the third
> day she feels dizzy. The doctor has a question: what is the most likely
> sequence of health conditions of the patient that would explain these
> observations? This is answered by the Viterbi algorithm.

In this example, the initial probabilities are given as:
* Healthy: 60%
* Fever: 40%

Each day, a healthy patient has 30% chance of transitioning to the fever state,
and a patient with fever has a 40% chance of transitioning to the healthy
state. The probability tables for each symptom given the patient state are:

Healthy:
* Normal: 50%
* Cold: 40%
* Dizzy: 10%

Fever:
* Normal: 10%
* Cold: 30%
* Dizzy: 60%

On each day, the test program's patient presents the following symptoms:
1. Normal
2. Cold
3. Dizzy

And finally, the most likely conclusion (which the program easily determines)
is that the patient is healthy on days 1 and 2, with a fever on day 3.