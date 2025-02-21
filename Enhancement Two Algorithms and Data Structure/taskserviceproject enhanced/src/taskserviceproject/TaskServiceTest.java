package taskserviceproject;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.List;

public class TaskServiceTest {
    private TaskService taskService;

    @BeforeEach
    public void setUp() {
        taskService = new TaskService();
    }

    @Test
    public void testAddTask() {
        taskService.addTask("1", "Task1", "Description1");
        Task task = taskService.getTask("1");
        assertNotNull(task);
        assertEquals("Task1", task.getName());
        assertEquals("Description1", task.getDescription());
    }

    @Test
    public void testAddTaskWithDuplicateId() {
        taskService.addTask("1", "Task1", "Description1");
        assertThrows(IllegalArgumentException.class, () -> {
            taskService.addTask("1", "Task2", "Description2");
        });
    }

    @Test
    public void testDeleteTask() {
        taskService.addTask("1", "Task1", "Description1");
        taskService.deleteTask("1");
        assertNull(taskService.getTask("1"));
    }

    @Test
    public void testUpdateTaskName() {
        taskService.addTask("1", "Task1", "Description1");
        taskService.updateTaskName("1", "UpdatedTask1");
        Task task = taskService.getTask("1");
        assertEquals("UpdatedTask1", task.getName());
    }

    @Test
    public void testUpdateTaskDescription() {
        taskService.addTask("1", "Task1", "Description1");
        taskService.updateTaskDescription("1", "UpdatedDescription1");
        Task task = taskService.getTask("1");
        assertEquals("UpdatedDescription1", task.getDescription());
    }

    @Test
    public void testSearchTasksByName() {
        taskService.addTask("1", "Fix Bug", "Resolve error");
        taskService.addTask("2", "Feature Dev", "Implement login");
        List<Task> results = taskService.searchTasks("Fix");
        assertEquals(1, results.size());
        assertEquals("Fix Bug", results.get(0).getName());
    }

    @Test
    public void testSearchTasksByDescription() {
        taskService.addTask("1", "Bug Fix", "Resolve error");
        taskService.addTask("2", "Feature Dev", "Implement login");
        List<Task> results = taskService.searchTasks("Implement");
        assertEquals(1, results.size());
        assertEquals("Feature Dev", results.get(0).getName());
    }

    @Test
    public void testSearchTasksNoMatch() {
        taskService.addTask("1", "Task1", "Description1");
        List<Task> results = taskService.searchTasks("Nonexistent");
        assertEquals(0, results.size());
    }
}
