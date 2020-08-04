// This file should contain unit tests for all the 
// public interfaces of the classes that you implement
#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
#include "testcards.h"

using namespace std;

int main() {
  runAll();
  return 0;
}

void runAll() {
  test_constructor();
  test_append();
  test_delete();
  test_find();
  test_copy_assignment();
}

void test_constructor() {
  START_TEST("test_constructor");
  CardList l1("Lee");
  assertEquals("Lee", l1.getName(), "test_constructor");
  END_TEST("test_constructor");
}

void test_append() {
  START_TEST("test_append");
  CardList l1("TA");
  l1.append('s','a');
  assertEquals("s a\n", l1.getCards(),"test_append");
  l1.append('h','k');
  assertEquals("s a\nh k\n", l1.getCards(),"test_append");
  END_TEST("test_append");
}

void test_delete() {
  START_TEST("test_delete");
  CardList l1("TT");
  l1.append('s','a');
  l1.append('s','j');
  l1.append('h','2');
  l1.removeCard("s a");
  assertEquals("s j\nh 2\n", l1.getCards(), "test_delete");
  END_TEST("test_delete");
}

void test_find() {
  START_TEST("test_find");
  CardList l1("TT");
  assertEquals(false, l1.findValue("s a"), "test_find");
  l1.append('s','a');
  l1.append('s','j');
  l1.append('h','2');
  assertEquals(true, l1.findValue("s a"), "test_find");
  assertEquals(false, l1.findValue("h 3"), "test_find");
  END_TEST("test_find");
}

void test_copy_assignment() {
  START_TEST("test_copy_assignment");
  CardList l1("TT");
  l1.append('s','a');
  l1.append('s','j');
  l1.append('h','2');
  CardList l2("tt");
  l2=l1;
  assertEquals(true, l1.getCards() == l2.getCards(), "test_copy_assignment");
  END_TEST("test_copy_assignment");
}