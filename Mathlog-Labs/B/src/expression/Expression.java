package expression;

import java.util.List;

public interface Expression {
    String toTree();
    List<Expression> get(Expression expression) throws Exception;

}
