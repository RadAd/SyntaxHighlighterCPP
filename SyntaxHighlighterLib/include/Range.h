#ifndef RANGE_H
#define RANGE_H

class Range
{
public:
    Range(size_t s, size_t e)
        : start(s)
        , end(e)
    {
    }

    bool empty() const
    {
        return end <= start;
    }

    size_t start;
    size_t end;
};

inline bool operator<(const Range& l, const Range& r)
{
    if (l.start == r.start)
        return l.end < r.end;
    else
        return l.start < r.start;
}

#endif
