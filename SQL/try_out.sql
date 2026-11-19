CREATE TABLE IF NOT EXISTS observations (
    time TIME NOT NULL,
    subject VARCHAR(10) NOT NULL,
    val INT NOT NULL
);

INSERT INTO observations (time, subject, val) VALUES
('07:00:00', 'st113', 10),
('07:15:00', 'st113', 9),
('07:30:00', 'st113', 25),
('07:45:00', 'st113', 20),
('07:00:00', 'xh458', 0),
('07:15:00', 'xh458', 10),
('07:30:00', 'xh458', 5),
('07:45:00', 'xh458', 30),
('08:00:00', 'xh458', 25);

select