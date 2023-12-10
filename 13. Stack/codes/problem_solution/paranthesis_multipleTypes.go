package main

import "fmt"

type testStack struct {
	elements []int
}

func (t *testStack) push(value int) {
	t.elements = append(t.elements, value)
}

func (t *testStack) pop() int {
	size := len(t.elements)
	goinTopopped := t.elements[size-1]
	t.elements = t.elements[:size-1]
	return goinTopopped
}

//will only check the paranthesis of different types, irrespective of what logic does the exp make
func (t *testStack) isBalanced(exp string) bool {
	for i := 0; i < len(exp); i++ {
		switch exp[i] {
		case '{':
			t.push('{')
		case '}':
			if len(t.elements) > 0 {
				v := t.pop()
				if v != '{' {
					return false
				}
			} else {
				return false
			}
		case '[':
			t.push('[')
		case ']':
			if len(t.elements) > 0 {
				v := t.pop()
				if v != '[' {
					return false
				}
			} else {
				return false
			}
		case '(':
			t.push('(')
		case ')':
			if len(t.elements) > 0 {
				v := t.pop()
				if v != '(' {
					return false
				}
			} else {
				return false
			}
		default:
			continue
		}
	}
	if len(t.elements) != 0 {
		return false
	}
	return true
}

func main() {
	t1 := testStack{}
	exp := "{(a+b{[c-a]})-[a*b]}"
	b := t1.isBalanced(exp)

	fmt.Println(b)
}
