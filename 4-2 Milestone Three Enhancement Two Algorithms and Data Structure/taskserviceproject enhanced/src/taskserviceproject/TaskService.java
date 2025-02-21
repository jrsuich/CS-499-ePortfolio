package taskserviceproject;

import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.List;

public class TaskService {
    private Map<String, Task> tasks = new TreeMap<>();

    // Add Task
    public void addTask(String taskId, String name, String description) {
        validateTask(taskId, name, description);
        if (tasks.containsKey(taskId)) {
            throw new IllegalArgumentException("Task ID must be unique");
        }
        tasks.put(taskId, new Task(taskId, name, description));
    }

    // Delete Task
    public void deleteTask(String taskId) {
        tasks.remove(taskId);
    }

    // Update Name
    public void updateTaskName(String taskId, String name) {
        validateName(name);
        Task task = tasks.get(taskId);
        if (task != null) {
            task.setName(name);
        }
    }

    // Update Description
    public void updateTaskDescription(String taskId, String description) {
        validateDescription(description);
        Task task = tasks.get(taskId);
        if (task != null) {
            task.setDescription(description);
        }
    }

    // Get Task
    public Task getTask(String taskId) {
        return tasks.get(taskId);
    }

    // Search Tasks by Name or Description (Prefix Matching)
    public List<Task> searchTasks(String query) {
        return tasks.values().stream()
                .filter(task -> task.getName().toLowerCase().startsWith(query.toLowerCase()) || 
                                task.getDescription().toLowerCase().startsWith(query.toLowerCase()))
                .collect(Collectors.toList());
    }

    // Validation Logic
    private void validateTask(String taskId, String name, String description) {
        if (taskId == null || taskId.length() > 10) {
            throw new IllegalArgumentException("Invalid task ID");
        }
        validateName(name);
        validateDescription(description);
    }

    private void validateName(String name) {
        if (name == null || name.length() > 20) {
            throw new IllegalArgumentException("Invalid name");
        }
    }

    private void validateDescription(String description) {
        if (description == null || description.length() > 50) {
            throw new IllegalArgumentException("Invalid description");
        }
    }
}
