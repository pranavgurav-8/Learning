import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class UsersService {

  constructor(private http:HttpClient) { }
  getUserData() {
    let url = "https://jsonplaceholder.typicode.com/photos";
    return this.http.get(url);
  }
}
