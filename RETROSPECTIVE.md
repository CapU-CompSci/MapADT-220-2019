# Reflections on the Project
Comp220 @ Capilano U - Map ADT class collaboration project (2018)

## Meeting Project Requirements / Code Correctness
90% of the project requirements were completed by the project deadline.
In the world of software projects, that's actually pretty good.

_What was missing?_
  - a couple bugs needed to be fixed (See Issues #119, #120, #124)
  - memory leak in mapClear() (see #126)
  - hashmap.c had some serious code duplication issues resulting in at least 2 bugs (See #122 + #123)
  - map-test.c was a bit weak - the tests were incomplete and the code a bit unstructured (See #118)
  - wordcloud.c required one last algorithm to be complete (See #117)
  - final code cleanup (see #125)

## Code Quality
I have only done a rough code review, but here is my preliminary analysis
of the quality of code produced on this project:

  - `treemap.c`  the code here is mostly very high quality
    - code conventions are consistent
    - code is well-structured and organized neatly
    - algorithms are nicely decomposed -- good abstraction and re-use
    - code documentation is clean and useful
  - `hashmap.c`  the code here was more slap-dash
    - capitalization, naming, and even indentation was inconsistent (see #123)
    - code was a bit messy, disorganized in places
    - tons of duplicate code -- so much, I had to fix it (see #122)
    - naming choices did not always make code self-documenting
  - `map-test.c`  a reasonable first draft 
    - code was tidy, well-organized, and logically sequenced
    - did not take advantage of repeating patterns and things that could be automated (see #118)
    - was imcomplete (well, complete set of tests were written by commented out)
  - `wordcloud.c`   clean, solid code
    - this code is simple, clean and easy to following
    - very good use of decomposition to improve re-use, abstraction, and 
    - early on, some ideas were coupled too tightly the concept of Map-as-a-Tree
    - incomplete -- missing one key algorithm (see #117)

In defence of `hashmap.c`, this ADT was a much bigger challenge, since we had really
not covered hash tables much in class, so students were having to learn more
as they were designing and developing code.  But I can't help but think that 
some additional discipline here - in terms of following conventions and staying
organized - would have saved a lot of confusion (and time).

## Teamwork and Communications
Good teamwork and communications skills make up at least 50% of project success.
A large part of this project was about learning new tools and techniques
for working in a team (IDE, Version Control System, Issues board, Slack, ...).

This was a great success -- went much smoother than I would have predicted.
  - project got off to a rough start when a ton of very hastily written, buggy code got committed
  - it took a major effort to work through all that bad code and repair it
  - but you did!  Creating over 100 Issues along the way!
  - several student, in particular (you know who you are), took a lead role in managing team communications
    - setting up the Slack channel was a genius idea, and helped a lot
    - taking the Issues board seriously, and documenting bugs, questions, and progress
    - taking time to discuss issues and solutions before plunging into code.

Overall, especially for a group this large, with minimal meddling from your project leader,
the level of teamwork and communication exhibited on this project demonstrates a level
of maturity and professionalism quite far beyond what one might expect from a 2nd year class.

## Work Sharing
On any team project, work is never distributed evenly.
There are always those who take leadership roles, and those more comfortable following.
Those who do more than their fair share of the heavy lifting,
and those willing to ride coat tails of others.
This project was no different, I think.

I have not completed a detailed analysis yet, but my intuition is that the team
is split fairly neatly into 2 groups - those who took on a fair share of work
and responsibilities, and those that did very little.
  - among those in the former group (you know who you are):
     - a few showed real leadership to ensure the project's success
     - many spent more time and effort than was required
     - all, I'm certain, learned many many lessons about software I could never have taught in class.
  - for those in the later group (hopefully you can recognize who you are):
     - there might be many reasons to hold back:
       - the fear of getting started
       - uncertainty about what to do next or how to be of service
       - lack of confidence
       - procrastination
     - regardless of what you choose to do in life, you will need to learn to work with others
     - "soft skills" are key 
        - teamwork, communications, humility, knowing when to ask for help
        - these are equally imporant to the technical skills you are acquiring   
     - you can only learn by failing
        - look how badly the first attempt to write this code failed!
        - but look how much those who made that initial effort were able to learn from it.
     - do not fear failure -- embrace it, learn from it -- what doesn't kill you makes you stronger.
     - I strongly encourage you to take more of a leadership role on your next team project - what can you lose?
