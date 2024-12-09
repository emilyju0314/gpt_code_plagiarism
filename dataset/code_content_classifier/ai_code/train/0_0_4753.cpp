To help you with this question, I will provide a high-level pseudocode for the solution:

1. Read the number of records from input.
2. For each record:
   3. Read the input for the record, which includes the team you are asked to calculate the probability for, and the match results for the group.
   4. Parse the input to extract the information regarding matches (whether played or not) and goals scored by each team.
   5. Simulate all possible outcomes for the remaining two matches for the specified team.
   6. Calculate the probability of each outcome based on the given probability distribution.
   7. For each outcome, calculate the points, goal difference, and goals scored for the team.
   8. Count the number of outcomes in which the team qualifies for the next round (finishes in the top 2).
   9. Calculate the probability of the team qualifying by dividing the count of qualifying outcomes by the total number of outcomes.
   10. Output the probability with exactly seven digits after the decimal point.

This pseudocode outlines the general approach to solving the problem. You will need to convert this into C++ code and implement the necessary functions to parse input, simulate outcomes, calculate probabilities, and output the results. If you encounter any specific issues or have further questions, feel free to ask for more help.