package taskserviceproject;

import java.util.HashMap;
import java.util.Map;

public class TaskService {
    private Map<String, Task> tasks = new HashMap<>();

    public void addTask(String taskId, String name, String description) {
        if (tasks.containsKey(taskId)) {
            throw new IllegalArgumentException("Task ID must be unique");
        }
        Task task = new Task(taskId, name, description);
        tasks.put(taskId, task);
    }

    public void deleteTask(String taskId) {
        tasks.remove(taskId);
    }

    public void updateTaskName(String taskId, String name) {
        Task task = tasks.get(taskId);
        if (task != null) {
            task.setName(name);
        }
    }

    public void updateTaskDescription(String taskId, String description) {
        Task task = tasks.get(taskId);
        if (task != null) {
            task.setDescription(description);
        }
    }

    public Task getTask(String taskId) {
        return tasks.get(taskId);
    }
}