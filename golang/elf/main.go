package main

type Node struct {
	val  int
	next *Node
}

// Queue 队列
type Queue struct {
	top    *Node
	bottom *Node
	length int
}

func (q *Queue) List() {
	current := q.top
	for {
		if current == nil {
			break
		}
		println(current.val)
		current = current.next
	}
}

func (q *Queue) Reserve() {
	prev := q.top
	current := q.top.next
	prev.next = nil
	for {
		if current == nil {
			break
		}
		next := current.next
		current.next = prev
		prev = current
		current = next
	}
	q.top, q.bottom = q.bottom, q.top
}

func (q *Queue) Shift() int {
	//TODO implement me
	current := q.top
	q.top = current.next
	q.length--
	return current.val
}

func (q *Queue) Push(data int) {
	//TODO implement me
	v := newNode(data)
	q.length++
	if q.top == nil {
		q.top = v
	}
	if q.bottom != nil {
		q.bottom.next = v
	}
	q.bottom = v
}

func newNode(data int) *Node {
	return &Node{
		next: nil,
		val:  data,
	}
}

type QueueInterface interface {
	Shift() int
	Push(data int)
	Reserve()
	List()
}

var queue QueueInterface = &Queue{}

func main() {
	q := &Queue{}
	q.Push(1)
	q.Push(2)
	q.Push(3)
	q.Push(5)

	q.List()

	q.Reserve()
	q.List()

	println(q.length)
}
