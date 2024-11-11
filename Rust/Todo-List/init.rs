struct Task {
    name: char[32],
    desc: char[256],
    is_completed: bool,
    subtasks: Vec<Task>, 
}
