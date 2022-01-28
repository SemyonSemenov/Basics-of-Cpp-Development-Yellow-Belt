#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <exception>
#include <stdexcept>
#include <numeric>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    a %= b;
    return gcd(b, a);
}

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator * denominator > 0) {
            num = abs(numerator);
            den = abs(denominator);
        }
        else if (numerator * denominator < 0) {
            num = -abs(numerator);
            den = abs(denominator);
        }
        else {
            num = 0;
            den = 1;
        }
    }

    int Numerator() const {
        return num / gcd(abs(num), abs(den));
    }

    int Denominator() const {
        return den / gcd(abs(num), abs(den));
    }

private:
    int num;
    int den;
};

bool operator!=(const Rational& lhs, const Rational& rhs) {
    // a / b == c / d <=> ad == bc
    if (lhs.Numerator() == rhs.Numerator() && rhs.Denominator() == lhs.Denominator()) {
        return false;
    }
    return true;
}

ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception & e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

void TestСonstructor() {
    AssertEqual(Rational(), Rational(0, 1));
}

void TestReduction() {
    AssertEqual(Rational(1, 2), Rational(2, 4));
    AssertEqual(Rational(1, 3), Rational(3, 9));
    AssertEqual(Rational(1, 4), Rational(4, 16));
}

void TestNegativity() {
    AssertEqual(Rational(1, -2), Rational(-1, 2));
    AssertEqual(Rational(1, -4), Rational(-1, 4));
    AssertEqual(Rational(1, -8), Rational(-1, 8));
}

void TestPositivity() {
    AssertEqual(Rational(-1, -2), Rational(1, 2));
    AssertEqual(Rational(-1, -4), Rational(1, 4));
    AssertEqual(Rational(-1, -8), Rational(1, 8));
}

void TestZeroNumerator() {
    AssertEqual(Rational(0, 2), Rational(0, 1));
    AssertEqual(Rational(0, 4), Rational(0, 1));
    AssertEqual(Rational(0, 8), Rational(0, 1));
}

void TestAll() {
    TestRunner runner;
    runner.RunTest(TestСonstructor, "TestConstructor");
    runner.RunTest(TestReduction, "TestReduction");
    runner.RunTest(TestNegativity, "TestNegativity");
    runner.RunTest(TestPositivity, "TestPositivity");
    runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
}

int main() {
    TestAll();
    return 0;
}
