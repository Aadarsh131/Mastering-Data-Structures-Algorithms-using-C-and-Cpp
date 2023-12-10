use std::cell::RefCell;
use std::rc::Rc;

type SingleLink = Option<Rc<RefCell<Node>>>;

struct Node {
    value: i32,
    next: SingleLink,
}

struct LinkedList {
    head: SingleLink,
    tail: SingleLink,
    pub length: u64,
}

impl Node {
    fn new(value: i32) -> Rc<RefCell<Node>> {
        Rc::new(RefCell::new(Node {
            value: value,
            next: None,
        }))
    }
}

impl LinkedList {
    fn new_empty() -> LinkedList {
        LinkedList {
            head: None,
            tail: None,
            length: 0,
        }
    }

    pub fn append(&mut self, value: i32) {
        let new_node = Node::new(value);

        match &self.tail {
            Some(v) => {
                v.borrow_mut().next = Some(new_node.clone());
            }
            None => self.head = Some(new_node.clone()),
        };
        self.length += 1;
        self.tail = Some(new_node);
    }

    pub fn display(&self) {
        if let None = &self.tail {
            println!("empty");
        }

        if let Some(_) = &self.head {
            println!("Node count {}", &self.length);
        }
    }
}

fn main() {
    let mut a = LinkedList::new_empty();
    a.append(43);
    a.display();

    // let mut a = Option::Some(45);
    // let b = a.take();

    // assert_eq!(a, None);
    // assert_eq!(b, Some(45));
}
