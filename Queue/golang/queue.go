package main

import "fmt"

type Queue struct {
	items []int
}

func (q *Queue) Enqueue(val int){
	q.items = append(q.items, val)
}

func (q *Queue) Dequeue() (int,bool) {
	if len(q.items) == 0 {
		return 0,false
	}

	val := q.items[0]
	q.items = q.items[1:]
	return val,true
}

func (q *Queue) Peek() (int,bool) {
	if len(q.items) == 0 {
		return 0,false
	}

	return q.items[0],true
}

func main() {
	q := &Queue{}

	q.Enqueue(10)
	q.Enqueue(20)
	q.Enqueue(30)

	val,_ := q.Dequeue()
	fmt.Println(val)

	peek, _ := q.Peek()
	fmt.Println(peek)
}
