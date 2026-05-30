package main

import "fmt"

type Stack struct {
	items []int
}

func (st *Stack) Push(data int){
	st.items = append(st.items,data)
}

func (st *Stack) Pop() (int,bool) {
	if len(st.items) == 0{
		return 0,false
	}

	topIndex := len(st.items) - 1
	val := st.items[topIndex]
	st.items = st.items[:topIndex]

	return val,true
}

func (st *Stack) Peek() (int,bool) {
	if len(st.items) == 0{
		return 0,false
	}
	return st.items[len(st.items)-1],true
}

func (st *Stack) isEmpty() bool {
	return len(st.items) == 0
}

func main() {
	s := &Stack{}

	s.Push(10)
	s.Push(20)
	s.Push(30)

	val, _ := s.Pop()
	fmt.Println(val)

	top, _ := s.Peek()
	fmt.Println(top)
}
