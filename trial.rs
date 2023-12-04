fn find<T>(item: T, stack: &Vec<T>) -> std::Option<T> {
    for _,i in stack{
        println!("{}",i);
    }
}
fn main() {
    let stack = Vec![3,2,5,8,4,1];
    find()
}
