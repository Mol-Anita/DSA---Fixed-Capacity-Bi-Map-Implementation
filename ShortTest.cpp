#include "ShortTest.h"
#include <assert.h>
#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <utility>


void testAll() { //call each function to see if it is implemented
	FixedCapBiMap m(10);
	assert(m.isEmpty() == true);
	assert(m.size() == 0); //add elements
	assert(m.add(5,5)==true);
	assert(m.add(1,111)==true);
	assert(m.add(10,110)==true);
	assert(m.add(7,7)==true);
	assert(m.add(1,1)==true); // this is the second value for key 1
	assert(m.add(1, 3) == false); // we cannot add a third value
	assert(m.add(10,10)==true);
	assert(m.add(-3,-3)==true);
	assert(m.size() == 7);
	std::pair<TValue, TValue> res = m.search(10);
	std::pair<TValue, TValue> ans1(110, 10);
	std::pair<TValue, TValue> ans2(10, 110);
	std::pair<TValue, TValue> ans3(NULL_TVALUE, NULL_TVALUE);
	assert(((res == ans1) || (res == ans2)));
	assert(m.search(16) == ans3);
	assert(m.remove(1,1) == true);
	assert(m.remove(6, 6) == false);
	assert(m.remove(5, 7) == false);
	assert(m.isEmpty() == false);
	assert(m.isFull() == false);
	assert(m.size() == 6);


	TElem e;
	FixedCapBiMapIterator id = m.iterator();
	id.first();
	int s1 = 0, s2 = 0;
	while (id.valid()) {
		e = id.getCurrent();
		s1 += e.first;
		s2 += e.second;
		id.next();
	}
	assert(s1 == 30);
	assert(s2 == 240);

}

void testRemoveKey() {
	FixedCapBiMap m(5);
	m.add(2, 6);
	m.add(1, 2);
	m.add(5, 6);
	m.add(1, 8);
	m.add(2, 4);
	std::pair<TValue, TValue> res = m.removeKey(1);
	assert(res.first == 2 && res.second == 8);
	res = m.removeKey(5);
	assert(res.first == 6 && res.second == NULL_TVALUE);
	res = m.removeKey(10);
	assert(res.first == NULL_TVALUE && res.second == NULL_TVALUE);
	res = m.removeKey(2);
	assert(res.first == 6 && res.second == 4);


}


