#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    inline int min(int a, int b){
        return a < b ? a: b;
    }
    inline int max(int a, int b){
        return a > b ? a: b;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int iterStart, iterEnd;

        vector<vector<Interval>::iterator> overlaps;
        vector<Interval>::iterator iter;
        // judge which of the intevals overlaps with newInterval
        for(iter = intervals.begin(); iter != intervals.end(); iter++){
            iterStart = (*iter).start;
            iterEnd = (*iter).end;
            // if intervals overlaps with newInterval
            if(     (newInterval.start >= iterStart && newInterval.start <= iterEnd) ||
                    (newInterval.end   >= iterStart && newInterval.end   <= iterEnd) ||
                    (iterStart >= newInterval.start && iterStart <= newInterval.end) ||
                    (iterEnd   >= newInterval.start && iterEnd   <= newInterval.end)) {
                overlaps.push_back(iter);
            }
        }

        // if no overlap
        if(overlaps.empty()){
            for(iter = intervals.begin(); iter!=intervals.end() && (*iter).start < newInterval.start; iter++);
            intervals.insert(iter, newInterval);
        // if there's overlap
        } else {
            (*overlaps[0]).start = min((*overlaps[0]).start, newInterval.start);
            (*overlaps[0]).end = max((*overlaps.back()).end, newInterval.end);
            if(overlaps.size() > 1)
                intervals.erase(overlaps[1], overlaps.back() + 1);
        }
        return intervals;
    }
};
