FROM debian:latest

WORKDIR /Solve_Me

COPY Solve_Me.c /Solve_Me/Solve_Me.c

RUN apt update && \
	apt -y install gcc && \
	gcc Solve_Me.c -o Solve_Me

CMD ["./Solve_Me"]

