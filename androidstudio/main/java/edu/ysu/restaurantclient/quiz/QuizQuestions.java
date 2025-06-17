package edu.ysu.restaurantclient.quiz;

//This class handles the quiz questions as a class.
public class QuizQuestions {

    private String question; //The question as it appears to the user.
    private QuizAnswers[] answers; //The answers. These are its own class.
    private QuizQuestionType questionType; //What kind of question it is.

    //Constructor. All fields are required.
    public QuizQuestions(String _question, QuizAnswers[] _answers, QuizQuestionType _questionType) {

        this.question = _question;
        this.answers = _answers;
        this.questionType = _questionType;

    }

    //Takes the index of the answer that the user chose. Returns true if it was a correct answer, and false if it was not.
    public boolean checkAnswers(int questionIndex) {

        return this.answers[questionIndex].isCorrect();

    }

    //Basic getters
    //Suggestion: To get the QuizAnswers' string, use getAnswers into a new array and invoke getAnswer on each answer in the new array.

    public String getQuestion() {
        return question;
    }

    public QuizAnswers[] getAnswers() {
        return answers;
    }

    public QuizQuestionType getQuestionType() {
        return questionType;
    }

}
