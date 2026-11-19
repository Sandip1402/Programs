// function addTwo(num: number, isPaid: boolean = false): number{
//     return num + 2;
// }

// addTwo(4); 
 
// let arr = ["1", 2, false];

// let arr2 = arr.map(item => {
//     return item * 2;
// })

// console.log(arr2);

// function handleError(errmsg: string):never {
//     throw new Error(errmsg);
// }


// function createUser({name, age} : {name: string, age: number}):{} {
//     return {name, age};
// }

// // let newUser = {name: "sandip", age: 22, email: "s@google.com"};
// let newUser = createUser({name: 'sandip', age:22});
// console.log(newUser);


type User = {
    name: string;
    email: string;
    isAcive: boolean
}

function createUser(user:User) : User {
    return user;
}

export {}