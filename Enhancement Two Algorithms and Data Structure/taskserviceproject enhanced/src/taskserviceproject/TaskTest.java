package taskserviceproject;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

public class TaskTest {

    @Test
    public void testTaskCreation() {
        Task task = new Task("1", "Task1", "Description1");
        assertNotNull(task);
        assertEquals("1", task.getTaskId());
        assertEquals("Task1", task.getName());
        assertEquals("Description1", task.getDescription());
    }

    @Test
    public void testTaskNameUpdate() {
        Task task = new Task("1", "Task1", "Description1");
        task.setName("UpdatedTask1");
        assertEquals("UpdatedTask1", task.getName());
    }

    @Test
    public void testTaskDescriptionUpdate() {
        Task task = new Task("1", "Task1", "Description1");
        task.setDescription("UpdatedDescription1");
        assertEquals("UpdatedDescription1", task.getDescription());
    }

    @Test
    public void testInvalidTaskId() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Task("12345678901", "Task", "Description");
        });
    }

    @Test
    public void testInvalidTaskName() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Task("1", "ThisNameIsWayTooLongForTheTaskNameField", "Description");
        });
    }

    @Test
    public void testInvalidTaskDescription() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Task("1", "Task", "This description is definitely way too long for the allowed description field.");
        });
    }
    @Test
    public void testNullTaskId() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Task(null, "TaskName", "Description");
        });
    }

    @Test
    public void testNullTaskName() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Task("1", null, "Description");
        });
    }

    @Test
    public void testNullTaskDescription() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Task("1", "TaskName", null);
        });
    }
}

