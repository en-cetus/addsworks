#include "BigNumCalc.h"
#include <cctype>
#include <algorithm>

std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> res;

    for (char c : numString) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            res.push_back(c - '0');
        }
    }
    if (res.empty()) {
        res.push_back(0);
    }
    stripLeadingZeros(res);
    return res;
}

void BigNumCalc::stripLeadingZeros(std::list<int>& n) const {
    while (n.size() > 1 && !n.empty() && n.front() == 0) {
        n.pop_front();
    }
}

int BigNumCalc::cmp(const std::list<int>& a, const std::list<int>& b) const {
    if (a.size() < b.size()) return -1;
    if (a.size() > b.size()) return  1;
    auto ia = a.begin();
    auto ib = b.begin();
    for (; ia != a.end() && ib != b.end(); ++ia, ++ib) {
        if (*ia < *ib) return -1;
        if (*ia > *ib) return  1;
    }
    return 0;
}

std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> res;
    int carry = 0;

    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int d1 = (it1 != num1.rend()) ? *it1 : 0;
        int d2 = (it2 != num2.rend()) ? *it2 : 0;
        int sum = d1 + d2 + carry;
        res.push_front(sum % 10);
        carry = sum / 10;
        if (it1 != num1.rend()) ++it1;
        if (it2 != num2.rend()) ++it2;
    }
    stripLeadingZeros(res);
    return res;
}

std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {

    if (cmp(num1, num2) < 0) {
        return std::list<int>{0};
    }

    std::list<int> res;
    int borrow = 0;

    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend()) {
        int d1 = (it1 != num1.rend()) ? *it1 : 0;
        int d2 = (it2 != num2.rend()) ? *it2 : 0;

        int cur = d1 - borrow - d2;
        if (cur < 0) {
            cur += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_front(cur);
        if (it1 != num1.rend()) ++it1;
        if (it2 != num2.rend()) ++it2;
    }

    stripLeadingZeros(res);
    return res;
}

std::list<int> BigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {

    if (num2.empty()) return std::list<int>{0};
    int digit = 0;
    if (num2.size() == 1) {
        digit = num2.front();
    } else {

        digit = num2.back();
    }

    if (digit == 0) return std::list<int>{0};
    if (digit == 1) return num1;

    std::list<int> res;
    int carry = 0;

    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int prod = (*it) * digit + carry;
        res.push_front(prod % 10);
        carry = prod / 10;
    }
    while (carry) {
        res.push_front(carry % 10);
        carry /= 10;
    }
    stripLeadingZeros(res);
    return res;
}