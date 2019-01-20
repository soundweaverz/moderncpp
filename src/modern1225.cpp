class Year
{
    private:
        int value_;
    
    public:
        explicit Year (int v) : value_{v} {}
        std::ostream& const print (std::ostream& os);
        Year& advance (Year& const other);
        bool equals const (Year& const other);
        bool less_than const (Year& const other);
};

std::ostream& Year::print(std::ostream& os) const
{
    return os << value_;
}

std::ostream& operator<<(std::ostream& os, Year& const year)
{
    return year.print(os)
}

Year& Year::advance(const Year& other)
{
    value_ += other.value;
    return *this;
}

bool Year::equals(Year& const other) const
{
    return value_ == other.value;
}

bool Year::less_than(Year& const other) const
{
    return value_ < other.value_;
}
