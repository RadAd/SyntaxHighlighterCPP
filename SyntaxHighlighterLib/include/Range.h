#ifndef RANGE_H
#define RANGE_H

class Range
{
public:
    Range(size_t s, size_t e)
        : begin(s)
        , end(e)
    {
    }

    bool empty() const
    {
        return end <= begin;
    }

    size_t length() const
    {
        return end - begin;
    }

    size_t begin;
    size_t end;
};

inline bool operator==(const Range& l, const Range& r)
{
    return (l.begin == r.begin) && (l.end == r.end);
}

inline bool operator!=(const Range& l, const Range& r)
{
    return (l.begin != r.begin) || (l.end != r.end);
}

inline bool operator<(const Range& l, const Range& r)
{
#if 0
    if (l.begin == r.begin)
        return l.end < r.end;
    else
        return l.begin < r.begin;
#else
    // This causes some confusion in the !(a < b) and !(b < a) does not mean they are equal
    // It does gives the advantage that map.lower_bound give the overlapping entry
    return l.end <= r.begin;
#endif
}

#endif
