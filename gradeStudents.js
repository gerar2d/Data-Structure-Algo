
function gradingStudents(grades) {
    return grades.map(grade => {
      var rounded = Math.ceil(grade / 5) * 5;
      return (grade < 38 || rounded - grade > 2) ? grade : rounded;
    });
  }

console.log(Math.ceil(42/5)*5)