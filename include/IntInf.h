/*
 * Infinity.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Christophe's Book
 */

#ifndef INTINF_H_
#define INTINF_H_

#define POS_INF true
#define NEG_INF false

namespace ece309 {

	typedef enum {INTEGER, POSITIVE_INFINTY, NEGATIVE_INFINITY, INDETERMINANT} Type_t;

	class IntInf {
	private:

		Type_t objectType;
		int integer_data;

		IntInf * null_object;

	public:
		IntInf ();
		IntInf (bool inf);
		IntInf (int num);

		Type_t getType();
		int getInteger();
		void setType(Type_t t, int num=0);
		void setInteger(int num);

		void setUpNullObject() {
			*null_object=IntInf(0);
			null_object->setType(INDETERMINANT);
		}
		bool checkForIntedterminant(Type_t t);
		bool checkForIntegerData(Type_t t);


		IntInf& operator=(const int val);
		IntInf& operator=(const IntInf & obj);
		IntInf operator+(const IntInf & obj);
		IntInf operator+(const int val);
		IntInf operator-(const IntInf & obj);
		IntInf operator-(const int val);
		IntInf operator*(const IntInf & obj);
		IntInf operator*(const int val);
		IntInf operator/(const IntInf & obj);
		IntInf operator/(const int val);
		bool operator==(const IntInf & obj);
		bool operator==(const int val);
		bool operator>(const IntInf & obj);
		bool operator>(const int val);
		bool operator<(const IntInf & obj);
		bool operator<(const int val);

	};

}

#endif /* INTINF_H_ */
