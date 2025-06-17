package edu.ysu.restaurantclient.quiz;

public class QuizAnswers {

    private String answer;
    private boolean correct;

    public QuizAnswers(String _answer, boolean _correct) {
        this.answer = _answer;
        this.correct = _correct;
    }

    public String getAnswer() {
        return answer;
    }

    public boolean isCorrect() {
        return correct;
    }

}
