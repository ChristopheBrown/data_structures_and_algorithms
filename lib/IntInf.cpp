/*
 * IntInf.cpp
 *
 *  Created on: Nov 19, 2018
 *      Author: Christophe's Book
 */


#include <stdlib.h>
#include <stdio.h>

#include "IntInf.h"

using namesapce ece309;

IntInf::IntInf() {
	setType(INDETERMINANT);
	integer_data = 0;
}

IntInf::IntInf(bool inf) {
	if (inf) setType(POSITIVE_INFINTY);
	else setType(NEGATIVE_INFINITY);
}

IntInf::IntInf(int num){
	setType(INTEGER,num);
}

void IntInf::setType(Type_t t, int num) {
	switch (t) {
	case POSITIVE_INFINTY:
		objectType = POSITIVE_INFINTY;
		break;
	case NEGATIVE_INFINITY:
		objectType = NEGATIVE_INFINITY;
		break;
	case INTEGER:
		objectType = INTEGER;
		integer_data = num;
		break;
	default:
		objectType = INDETERMINANT;
		integer_data = 666666666;
		break;
	}
}
Type_t IntInf::getType() {
	return this->objectType;
}

void IntInf::setInteger(int val) {
	this->integer_data = val;
}
int IntInf::getInteger() {
	return integer_data;
}

bool IntInf::checkForIntedterminant(Type_t type) {
	if (type == INDETERMINANT) return true;
	return false;
}

bool IntInf::checkForIntegerData(Type_t type) {
	if (type == INTEGER) return true;
	return false;
}

IntInf& IntInf::operator=(const int val){
	setType(INTEGER,val);
	return *this;
}

IntInf& IntInf::operator=(const IntInf & obj){
	if (checkForIntedterminant(obj.objectType)) setType(INDETERMINANT,0);
	else setType(obj.objectType,obj.integer_data);
	return *this;
}

IntInf IntInf::operator+(int val) {
	if ( checkForIntedterminant(objectType) ) return IntInf();
	if ( !checkForIntegerData(objectType) ) return (*this+IntInf(val));
	int result = this->getInteger() + val;
	return IntInf(result);
}

IntInf IntInf::operator+(const IntInf & obj) {
	Type_t t_lhs = objectType;
	int val_lhs = integer_data;

	Type_t t_rhs = obj.objectType;
	int val_rhs = obj.integer_data;

	if (checkForIntedterminant(t_lhs)|| checkForIntedterminant(t_rhs))
		return IntInf();

	switch (t_lhs) {
	case INTEGER:
		switch (t_rhs) {
		case INTEGER: return IntInf(val_lhs + val_rhs);
		case POSITIVE_INFINTY: return IntInf(POS_INF);
		case NEGATIVE_INFINITY: return IntInf(NEG_INF);
		default: return IntInf();
		}
		break;
	case POSITIVE_INFINTY:
		switch (t_rhs) {
		case INTEGER: return IntInf(POS_INF);
		case POSITIVE_INFINTY: return IntInf(POS_INF);
		case NEGATIVE_INFINITY: return IntInf();
		default: return IntInf();
		}
		break;
	case NEGATIVE_INFINITY:
		switch (t_rhs) {
		case INTEGER: return IntInf(NEG_INF);
		case POSITIVE_INFINTY: return IntInf();
		case NEGATIVE_INFINITY: return IntInf(NEG_INF);
		default: return IntInf();
		}
		break;
		default: return IntInf();
		break;
	}
	return IntInf();
}

IntInf IntInf::operator-(int val) {
	if ( checkForIntedterminant(this->objectType) ) return IntInf();
	if ( !checkForIntegerData(objectType) ) return (*this-IntInf(val));
	int result = this->getInteger() - val;
	return IntInf(result);
}

IntInf IntInf::operator-(const IntInf & obj) {
	Type_t t_lhs = objectType;
	int val_lhs = integer_data;

	Type_t t_rhs = obj.objectType;
	int val_rhs = obj.integer_data;

	if (checkForIntedterminant(t_lhs)|| checkForIntedterminant(t_rhs))
			return IntInf();

	switch (t_lhs) {
	case INTEGER:
		switch (t_rhs) {
		case INTEGER: return IntInf(val_lhs - val_rhs);
		case POSITIVE_INFINTY: return IntInf(NEG_INF);
		case NEGATIVE_INFINITY: return IntInf(POS_INF);
		default: return IntInf();
		break;
		}
		break;
	case POSITIVE_INFINTY:
		switch (t_rhs) {
		case INTEGER: return IntInf(POS_INF);
		case POSITIVE_INFINTY: return IntInf(POS_INF);
		case NEGATIVE_INFINITY: return IntInf(POS_INF);
		default: return IntInf();
		break;
		}
		break;
	case 2:
		switch (t_rhs) {
		case INTEGER: return IntInf(NEG_INF);
		case POSITIVE_INFINTY: return IntInf(NEG_INF);
		case NEGATIVE_INFINITY: return IntInf(NEG_INF);
		default: return IntInf();
		break;
		}
		break;
		default: return IntInf();
		break;
	}
	return IntInf();
}

IntInf IntInf::operator*(int val) {
	if ( checkForIntedterminant(this->objectType) ) return IntInf();
	if (val == 0) return IntInf(0);
	if ( !checkForIntegerData(objectType) ) return (*this*IntInf(val));
	int result = this->getInteger() * val;
	return IntInf(result);
}

IntInf IntInf::operator*(const IntInf & obj) {
	Type_t t_lhs = objectType;
	int val_lhs = integer_data;

	Type_t t_rhs = obj.objectType;
	int val_rhs = obj.integer_data;

	if (checkForIntedterminant(t_lhs) || checkForIntedterminant(t_rhs))
			return IntInf();

	if (!t_lhs && !t_rhs)
		if (val_lhs * val_rhs == 0) return IntInf(0);
		else return IntInf(val_lhs * val_rhs);
	else if (t_lhs == t_rhs) return IntInf(POS_INF);
	else if (t_lhs * t_rhs == POSITIVE_INFINTY * NEGATIVE_INFINITY) return IntInf(NEG_INF);
	else if (t_lhs + t_rhs == POSITIVE_INFINTY && val_rhs > 0) return IntInf(POS_INF);
	else if (t_lhs + t_rhs == POSITIVE_INFINTY && val_rhs < 0) return IntInf(NEG_INF);
	else if (t_lhs + t_rhs == NEGATIVE_INFINITY && val_rhs > 0) return IntInf(NEG_INF);
	else if (t_lhs + t_rhs == NEGATIVE_INFINITY && val_rhs < 0) return IntInf(POS_INF);
	return IntInf(false);
}

IntInf IntInf::operator/(int val) {
	if ( checkForIntedterminant(this->objectType) ) return IntInf();
	if (val == 0) return IntInf();
	if ( !checkForIntegerData(objectType) ) return (*this/IntInf(val));
	int result = this->getInteger() / val;
	return IntInf(result);
}

IntInf IntInf::operator/(const IntInf & obj) {
	Type_t t_lhs = objectType;
	int val_lhs = integer_data;

	Type_t t_rhs = obj.objectType;
	int val_rhs = obj.integer_data;

	if (checkForIntedterminant(t_lhs)|| checkForIntedterminant(t_rhs))
				return IntInf();


	if (!t_lhs && !t_rhs) return IntInf(val_lhs / val_rhs); // int / int
	else if (t_rhs != INTEGER) return IntInf(0); // [ANYTHING] / INF
	else if (t_lhs == POSITIVE_INFINTY) return IntInf(POS_INF); // +INF / int
	else if (t_lhs == NEGATIVE_INFINITY) return IntInf(NEG_INF); // -INF / int

	return IntInf(false);
}

bool IntInf::operator>(int val) {
	if (objectType == INDETERMINANT) return false;
	if ( !checkForIntegerData(objectType) ) return (*this>IntInf(val));
	return integer_data > val;
}

bool IntInf::operator>(const IntInf & obj) {
	Type_t t_lhs = objectType;
	int val_lhs = integer_data;

	Type_t t_rhs = obj.objectType;
	int val_rhs = obj.integer_data;

	switch (t_lhs) {
	case INTEGER:
		switch (t_rhs) {
		case INTEGER: return (val_lhs > val_rhs);
		case POSITIVE_INFINTY: return false;
		case NEGATIVE_INFINITY: return true;
		default: return false;
		break;
		}
		break;
	case POSITIVE_INFINTY:
		switch (t_rhs) {
		case INTEGER: return true;
		case POSITIVE_INFINTY: return false;
		case NEGATIVE_INFINITY: return true;
		default: return false;
		break;
		}
		break;
	case NEGATIVE_INFINITY:
		switch (t_rhs) {
		case INTEGER: return false;
		case POSITIVE_INFINTY: return false;
		case NEGATIVE_INFINITY: return false;
		default: return false;
		break;
		}
		break;
		default: return false;
	}

	return false;
}

bool IntInf::operator<(int val) {
	if (objectType == INDETERMINANT) return false;
	if ( !checkForIntegerData(objectType) ) return (*this<IntInf(val));
	return integer_data < val;
}

bool IntInf::operator<(const IntInf & obj) {
	Type_t t_lhs = objectType;
	int val_lhs = integer_data;

	Type_t t_rhs = obj.objectType;
	int val_rhs = obj.integer_data;

	switch (t_lhs) {
		case INTEGER:
			switch (t_rhs) {
			case INTEGER: return (val_lhs < val_rhs);
			case POSITIVE_INFINTY: return true;
			case NEGATIVE_INFINITY: return false;
			default: return false;
			break;
			}
			break;
		case POSITIVE_INFINTY:
			switch (t_rhs) {
			case INTEGER: return false;
			case POSITIVE_INFINTY: return false;
			case NEGATIVE_INFINITY: return false;
			default: return false;
			break;
			}
			break;
		case NEGATIVE_INFINITY:
			switch (t_rhs) {
			case INTEGER: return true;
			case POSITIVE_INFINTY: return true;
			case NEGATIVE_INFINITY: return false;
			default: return false;
			break;
			}
			break;
			default: return false;
		}
	return false;
}


bool IntInf::operator==(int val) {
	if (objectType == INDETERMINANT) {
		return false;
	}

	switch (objectType) {
	case INTEGER: return (integer_data == val);
	case POSITIVE_INFINTY:
	case NEGATIVE_INFINITY:
	case INDETERMINANT: return false;
	}
	return false;
}

bool IntInf::operator==(const IntInf & obj) {
	Type_t t_lhs = objectType;
	int val_lhs = integer_data;

	Type_t t_rhs = obj.objectType;
	int val_rhs = obj.integer_data;

	switch (t_lhs) {
		case INTEGER:
			switch (t_rhs) {
			case INTEGER: return (val_lhs == val_rhs);
			case POSITIVE_INFINTY: return false;
			case NEGATIVE_INFINITY: return false;
			default: return false;
			}
			break;
		case POSITIVE_INFINTY:
			switch (t_rhs) {
			case INTEGER: return false;
			case POSITIVE_INFINTY: return false;
			case NEGATIVE_INFINITY: return false;
			default: return false;
			}
			break;
		case NEGATIVE_INFINITY:
			switch (t_rhs) {
			case INTEGER: return false;
			case POSITIVE_INFINTY: return false;
			case NEGATIVE_INFINITY: return false;
			default: return false;
			}
			break;
			default: return true;
		}
	return false;
}



