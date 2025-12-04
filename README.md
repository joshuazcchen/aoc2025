doing advent of code 2025 in c++ w/ brief commentary on each day. none of this will be optimized or good code; im attempting for overall completion speed[^1] & valid solutions as opposed to time/space complexity.

big goal this year is to see how far i can make it, especially with a 12 day AOC as opposed to the standard 25.

![](https://github.com/joshuazcchen/aoc2025/blob/master/aocicon.png)

**Day 1:**
______
- I initially thought of implementing some form of Bertrand's Ballot Theorem here as an attempt at predicting what the second part of this question would be.
- However, that felt like overcomplicating a simple problem, as each line would only result in a subtraction or addition;
- Therefore, there was no reason to implement any more complex theorem than simply "if L, subtract; else add; if > 99, modulo 100; if < 0, 100 - modulo 100".
- Part 2 was similar to what I had expected, but still simpler than anticipated.
- More math logic was added regarding "wrapping", which ended up obtaining the solution.
- Great start to Advent of Code, haven't written C++ in a while so it's good to start refamiliarizing myself with it.
- Completed Day 1 relatively quickly, but the solution is nowhere near optimized; just functional.

**Day 2:**
_____
- In hindsight, this question was incredibly simple.
- However, I don't know why I was unable to spot the many obvious solutions and instaed opted to basically check each and every element imaginable.
- This did, however, make Part 2 a lot easier because the overly complicated logic involved in Part 1 ended up translating very well to getting Part 2's solution.
- Massive integers!
- I'm not proud of this code, but it got the job done and inevitably, I'm using this more as a refamiliarization exercise with C++.
- So maybe overly convoluted code actually helps me refamiliarize myself faster!

**Day 3:**
_____
- This question was definitely quick, a nice relief after Day 2.
- Somehow, my solution to Part 2 was basically "remove half of the logic from Part 1 then change the numbers around."
- Not the most optimized, but once again, given it's AOC, there's less of a goal of true optimization so much as completion/logic.

**Day 4:**
_____
- I think today's made me realize how much I both love and hate grid based questions.
- It was a simple question, but checking the edges and corners made the actual code significantly more cumbersome.
- For part 2, I just refactored my checks into a separate function returning the number of changed elements, and repeated checks until it returned 0 changes.

[^1] this does not mean it will be completed quickly upon release, it just means that I'm trying to get the solutions done as quickly as possible after I start doing the question.
