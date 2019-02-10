#include <iostream>

class Year
{
    private:
        int value_;
    
    public:
        explicit Year (int v) : value_{v} {}
        std::ostream& print (std::ostream& os) const;
        Year& advance (Year& const other);
        bool equals (Year& const other) const;
        bool less_than (Year& const other) const;
};

std::ostream& Year::print(std::ostream& os) const
{
    return os << value_;
}

std::ostream& operator<<(std::ostream& os, Year& const year)
{
    return year.print(os);
}

Year& Year::advance(Year& const other)
{
    value_ += other.value_;
    return *this;
}

bool Year::equals(Year& const other) const
{
    return value_ == other.value_;
}

bool Year::less_than(Year& const other) const
{
    return value_ < other.value_;
}
