grammar Expression;

@header {
package parser;
import expression.*;
}

expression returns [Expression expr] : disj=disjunction {$expr = $disj.expr;}
                                     | disj1=disjunction IMPLIES exp1=expression {$expr = new Implication($disj1.expr, $exp1.expr);};

disjunction returns [Expression expr] : conj=conjunction {$expr = $conj.expr;}
                                      | disj1=disjunction OR conj1=conjunction {$expr = new Disjunction($disj1.expr, $conj1.expr);};

conjunction returns [Expression expr] : neg=negation {$expr = $neg.expr;}
                                      | conj1=conjunction AND neg1=negation{$expr = new Conjunction($conj1.expr, $neg1.expr);};

negation returns [Expression expr] : pred=predicate {$expr = $pred.expr;}
                                   | NOT neg=negation {$expr = new Negation($neg.expr);}
                                   | OB exp=expression CB {$expr = $exp.expr;}
                                   | S var=variable DOT exp1=expression {$expr = new Formula($S.text, $var.expr, $exp1.expr);};

predicate returns [Expression expr] : PRED {$expr = new Pred($PRED.text);}
                                    | t1=term EQ t2=term {$expr = new Equals($t1.expr, $t2.expr);};
variable returns [Expression expr] : VAR {$expr = new Variable($VAR.text);};

term returns [Expression expr] : a=add {$expr = $a.expr;}
                               | t=term ADD a1=add {$expr = new Term($t.expr, $a1.expr);};

add returns [Expression expr] : m=mul {$expr = $m.expr;}|
                              | a=add MUL m1=mul {$expr = new Multiplied($a.expr, $m1.expr);};

mul returns [Expression expr] : var=variable {$expr = $var.expr;}
                              | OB t=term CB {$expr = $t.expr;}
                              | Z {$expr = new Zero();}
                              | m=mul IN {$expr = new Increment($m.expr);};

IMPLIES : '->';
OR : [\u007c];
AND : '&';
NOT : '!';
OB : '(';
CB : ')';
PRED : [A-Z];
VAR : [a-z];
S : [@?];
DOT : '.';
ADD : '+';
MUL : '*';
Z : '0';
IN : [\u0027];
EQ : '=';
