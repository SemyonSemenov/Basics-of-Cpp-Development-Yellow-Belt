#include "phone_number.h"
#include <vector>
#include <algorithm>
#include <iostream>

PhoneNumber::PhoneNumber(const string& international_number) {
	int first_minus = -1;
	int second_minus = -1;

	if (international_number.length() == 0) {
		throw invalid_argument("invalid format");
	}
	if (international_number[0] != '+') {
		throw invalid_argument("invalid format");
	}

	for (int i = 0; i < international_number.length(); ++i) {
		if (international_number[i] == '-') {
			if (first_minus == -1) {
				first_minus = i;
			}
			else if (second_minus == -1) {
				second_minus = i;
			}
		}
	}
	if (first_minus == -1 || second_minus == -1) {
		throw invalid_argument("invalid format");
	}

	PhoneNumber::country_code_ = international_number.substr(1, first_minus - 1);
	PhoneNumber::city_code_ = international_number.substr(first_minus + 1, second_minus - first_minus - 1);
	PhoneNumber::local_number_ = international_number.substr(second_minus + 1);

	if (PhoneNumber::country_code_ == "" || PhoneNumber::city_code_ == "" || PhoneNumber::local_number_ == "") {
		throw invalid_argument("invalid format");
	}
}

string PhoneNumber::GetCountryCode() const{
	return PhoneNumber::country_code_;
}

string PhoneNumber::GetCityCode() const {
	return PhoneNumber::city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return PhoneNumber::local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + PhoneNumber::country_code_ + "-" + PhoneNumber::city_code_ + "-" + PhoneNumber::local_number_;
}